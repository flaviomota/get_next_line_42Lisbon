#!bin/bash

pwd=`pwd`

echo "Downloading files:"

[ -d 42cursus_gnl_tests ] || git clone https://github.com/mrjvs/42cursus_gnl_te\
sts.git

[ -d get-next-line-testing-tools ] || git clone https://github.com/TinfoilPanca\
kes/get-next-line-testing-tools.git

[ -d 42TESTERS-GNL ] || git clone https://github.com/Mazoise/42TESTERS-GNL.git

[ -d gnlTester ] || git clone https://github.com/Tripouille/gnlTester.git

echo "Download complete."
echo "Running tests:"

cd $pwd/42cursus_gnl_tests
if [ ! -f ".altered" ]; then
	sed -i.tmp 's/.\/get_next_line/../'  Makefile && rm Makefile.tmp
	sed -i.tmp '12 s/\.\//bash &/' Makefile && rm Makefile.tmp
	sed -i.tmp '16 s/\.\//bash &/' Makefile && rm Makefile.tmp
	sed -i.tmp '52 s/\.\//bash &/' compile_and_run.sh && rm compile_and_run.sh.tmp
	sed -i.tmp '60 s/\.\//bash &/' compile_and_run.sh && rm compile_and_run.sh.tmp
	touch .altered
fi
make
sleep 2
make bonus

echo -e '\033[0m'

cd $pwd/get-next-line-testing-tools
if [ ! -f ".altered" ]; then
	sed -i.tmp 's/GNL_SOURCE_DIR = ..\/get_next_line/GNL_SOURCE_DIR = ../' Make\
file && rm Makefile.tmp

	sed -i.tmp '10 s/^/	char	t[11];/' moulitest_files/get_next_line_tests/te\
sts/41_hard_test_large_file.spec.c && rm moulitest_files/get_next_line_tests/te\
sts/41_hard_test_large_file.spec.c.tmp

	sed -i.tmp 's/read(fd3, NULL, 10);/read(fd3, \&t, 10);/' moulitest_files/ge\
t_next_line_tests/tests/41_hard_test_large_file.spec.c && moulitest_files/get_n\
ext_line_tests/tests/41_hard_test_large_file.spec.c.tmp

	sed -i.tmp '12 s/^/	char	t[11];/' moulitest_files/get_next_line_tests/te\
sts/42_hard_test_one_big_fat_line.spec.c && moulitest_files/get_next_line_tests\
/tests/42_hard_test_one_big_fat_line.spec.c.tmp

	sed -i.tmp 's/read(fd3, NULL, 10);/read(fd3, \&t, 10);/' moulitest_files/ge\
t_next_line_tests/tests/42_hard_test_one_big_fat_line.spec.c && moulitest_files\
/get_next_line_tests/tests/42_hard_test_one_big_fat_line.spec.c.tmp

	sed -i.tmp 's/..\/..\/..\/..\/get_next_line/..\/..\/..\/../' moulitest_file\
s/testframework/v3/Makefile && moulitest_files/testframework/v3/Makefile.tmp

	touch .altered
fi
make mtest_all

echo -e '\033[0m'

cd $pwd/42TESTERS-GNL
bash ./all_tests_with_bonus.sh

echo -e '\033[0m'

cd $pwd/gnlTester
make a

echo -e '\033[0m'