import unittest
import os
import subprocess
from tools import valgrind_wrapper


class TestAST(unittest.TestCase):
	context = os.path.split(os.path.dirname(__file__))[0]
	testing = os.path.dirname(__file__)
	mains = "%s/21sh_mains" % testing
	libsh = "%s/libsh.a" % context
	devnull = open("/dev/null", "w")
	bin = None
	valgrind_bin = False

	@staticmethod
	def compilation(cl, main_test):
		bin_name = "%s" % main_test.replace(".c", ".bin")
		cmd = "gcc -Wall -Werror -Wextra {main} {libsha} -l termcap -I {includessh} -I {includesft} {libfta} -o {output}".format(
				main="%s/%s" % (cl.mains, main_test),
				libsha="%s/libsh.a" % cl.context,
				includessh="%s/includes/" % cl.context,
				includesft="%s/libft/includes/" % cl.context,
				libfta="%s/libft/libft.a" % cl.context,
				output="%s/%s" % (cl.testing, bin_name))
		bin_path = "%s/%s" % (cl.testing, bin_name)
		assert subprocess.call(cmd.split(" ")) == 0
		assert os.path.isfile(bin_path) is True
		return bin_path

	@classmethod
	def setUpClass(cls):
		os.chdir("%s/test_ast" % cls.testing)
		assert subprocess.call(["make", "re", "-C", cls.context], stdout=cls.devnull) == 0
		cls.bin = TestAST.compilation(TestAST, "main_ast.c")
		if subprocess.call(["which", "valgrind"]) == 0:
			cls.valgrind_bin = True
		else:
			os.write(2, "\nVALGRIND NOT AVAILABLE\n")

	def valgrind(self, command, method_name, binary):
		if self.valgrind_bin:
			valgrind_wrapper(command, method_name, binary)

	def test_pipe_00(self):
		cmd = [self.bin, "/bin/ls -1 | /bin/cat -e"]
		out = subprocess.check_output(cmd)
		self.assertEqual("file0$\nfile1$\n", out)
		self.valgrind(cmd, self.test_pipe_00.__name__, self.bin)

	def test_pipe_01(self):
		out = subprocess.check_output(["env", "DEBUG21=TRUE", self.bin, "/bin/ls -1 | /bin/cat -e"])
		expect = \
			"[ast_build][/ast_build]\n" \
			"[ast_read]/bin/cat -e | /bin/ls -1 [/ast_read]\n" \
			"[ast_exec]file0$\nfile1$\n[/ast_exec]\n" \
			"[ast_clean][/ast_clean]\n"
		self.assertEqual(expect, out)

	def test_pipe_02(self):
		out = subprocess.check_output([self.bin, "/bin/ls -1r | /bin/cat -e"])
		self.assertEqual("file1$\nfile0$\n", out)

	def test_pipe_03(self):
		cmd = [self.bin, "/bin/ls -1r | /bin/cat -e | /usr/bin/sort"]
		out = subprocess.check_output(cmd)
		self.assertEqual("file0$\nfile1$\n", out)
		self.valgrind(cmd, self.test_pipe_03.__name__, self.bin)

	def test_pipe_04(self):
		cmd = [self.bin, "/bin/ls -1r | /bin/cat -e | /usr/bin/sort | /usr/bin/rev"]
		out = subprocess.check_output(cmd)
		self.assertEqual("$0elif\n$1elif\n", out)
		self.valgrind(cmd, self.test_pipe_04.__name__, self.bin)

	def test_solo_00(self):
		out = subprocess.check_output([self.bin, "/bin/ls -1"])
		self.assertEqual("file0\nfile1\n", out)

	def test_right_00(self):
		cmd = [self.bin, "/bin/ls -1 > %s" % self.test_right_00.__name__]
		out = subprocess.check_output(cmd)
		try:
			self.assertEqual("", out)
			with open("%s" % self.test_right_00.__name__, 'r') as f:
				self.assertEqual("file0\nfile1\n%s\n" % self.test_right_00.__name__, f.read())
				self.valgrind(cmd, self.test_right_00.__name__, self.bin)
		finally:
			os.remove("%s" % self.test_right_00.__name__)

	def test_right_01(self):
		cmd = [self.bin, "/bin/echo test0 > %s" % self.test_right_01.__name__]
		out = subprocess.check_output(cmd)
		try:
			self.assertEqual("", out)
			with open("%s" % self.test_right_01.__name__, 'r') as f:
				self.assertEqual("test0\n", f.read())
				self.valgrind(cmd, self.test_right_01.__name__, self.bin)
		finally:
			os.remove("%s" % self.test_right_01.__name__)

	def test_double_right_00(self):
		out = subprocess.check_output([self.bin, "/bin/echo test1 >> %s" % self.test_double_right_00.__name__])
		try:
			self.assertEqual("", out)
			with open("%s" % self.test_double_right_00.__name__, 'r') as f:
				self.assertEqual("test1\n", f.read())
		finally:
			os.remove("%s" % self.test_double_right_00.__name__)

	def test_double_right_01(self):
		out0 = subprocess.check_output([self.bin, "/bin/echo base0 >> %s" % self.test_double_right_01.__name__])
		with open("%s" % self.test_double_right_01.__name__, 'r') as f:
			self.assertEqual("base0\n", f.read())
		out1 = subprocess.check_output([self.bin, "/bin/echo base1 >> %s" % self.test_double_right_01.__name__])
		try:
			self.assertTrue(out0 == out1 == "")
			with open("%s" % self.test_double_right_01.__name__, 'r') as f:
				self.assertEqual("base0\nbase1\n", f.read())
		finally:
			os.remove("%s" % self.test_double_right_01.__name__)

	def test_double_right_pipe_00(self):
		cmd = [self.bin, "/bin/echo base0 | /bin/cat -e >> %s" % self.test_double_right_pipe_00.__name__]
		out0 = subprocess.check_output(cmd)
		with open("%s" % self.test_double_right_pipe_00.__name__, 'r') as f:
			self.assertEqual("base0$\n", f.read())
		out1 = subprocess.check_output([self.bin, "/bin/echo base1 >> %s" % self.test_double_right_pipe_00.__name__])
		try:
			self.assertTrue(out0 == out1 == "")
			with open("%s" % self.test_double_right_pipe_00.__name__, 'r') as f:
				self.assertEqual("base0$\nbase1\n", f.read())
			self.valgrind(cmd, self.test_double_right_pipe_00.__name__, self.bin)
		finally:
			os.remove("%s" % self.test_double_right_pipe_00.__name__)

	def test_double_right_pipe_01(self):
		out0 = subprocess.check_output([self.bin,
										"/bin/echo base0 | /bin/cat -e | /usr/bin/rev >> %s" % self.test_double_right_pipe_00.__name__])
		with open("%s" % self.test_double_right_pipe_00.__name__, 'r') as f:
			self.assertEqual("$0esab\n", f.read())
		out1 = subprocess.check_output(
				[self.bin,
				 "/bin/echo base1 | /bin/cat -e | /usr/bin/rev >> %s" % self.test_double_right_pipe_00.__name__])
		try:
			self.assertTrue(out0 == out1 == "")
			with open("%s" % self.test_double_right_pipe_00.__name__, 'r') as f:
				self.assertEqual("$0esab\n$1esab\n", f.read())
		finally:
			os.remove("%s" % self.test_double_right_pipe_00.__name__)

	def test_left_00(self):
		cmd = [self.bin, "/bin/cat < file0"]
		out = subprocess.check_output(cmd)
		self.assertEqual("ok", out)
		# safety below
		with open("file0", 'r') as f:
			self.assertEqual("ok", f.read())
		self.valgrind(cmd, self.test_left_00.__name__, self.bin)

	def test_left_pipe_00(self):
		cmd = [self.bin, "/bin/cat < file0 | /usr/bin/rev"]
		out = subprocess.check_output(cmd)
		try:
			self.assertEqual("ko\n", out)
		except AssertionError:
			self.assertEqual("ko", out)
		# safety below
		with open("file0", 'r') as f:
			self.assertEqual("ok", f.read())
		self.valgrind(cmd, self.test_left_pipe_00.__name__, self.bin)

	def test_left_pipe_01(self):
		out = subprocess.check_output(
				[self.bin, "/bin/cat < file0 | /usr/bin/rev > %s" % self.test_left_pipe_01.__name__])
		self.assertEqual("", out)
		# safety below
		with open("file0", 'r') as f:
			self.assertEqual("ok", f.read())
		try:
			with open(self.test_left_pipe_01.__name__, 'r') as f:
				out = f.read()
				try:
					self.assertEqual("ko\n", out)
				except AssertionError:
					self.assertEqual("ko", out)
		finally:
			os.remove(self.test_left_pipe_01.__name__)

	def test_left_pipe_02(self):
		cmd = [self.bin, "/bin/cat < file0 | /usr/bin/rev >> %s" % self.test_left_pipe_02.__name__]
		out1 = subprocess.check_output(cmd)
		self.assertEqual("", out1)
		out2 = subprocess.check_output(
				[self.bin, "/bin/cat < file0 | /usr/bin/rev >> %s" % self.test_left_pipe_02.__name__])
		self.assertEqual("", out2)
		# safety below
		with open("file0", 'r') as f:
			self.assertEqual("ok", f.read())
		try:
			with open(self.test_left_pipe_02.__name__, 'r') as f:
				out = f.read()
				try:
					self.assertEqual("ko\nko\n", out)
				except AssertionError:
					self.assertEqual("koko", out)
		finally:
			os.remove(self.test_left_pipe_02.__name__)
		self.valgrind(cmd, self.test_left_pipe_02.__name__, self.bin)
