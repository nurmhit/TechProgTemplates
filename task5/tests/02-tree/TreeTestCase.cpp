//
// Created by akhtyamovpavel on 5/1/20.
//


#include <boost/filesystem/fstream.hpp>
#include <boost/filesystem.hpp>
#include "TreeTestCase.h"
#include "Tree.h"

TEST(TestCase2, FakeDir) {
  ASSERT_THROW(GetTree("some1", true), std::invalid_argument);
}


TEST(TestCase2, JustFile) {
  boost::filesystem::ofstream file("just_file");
  ASSERT_THROW(GetTree("just_file", true), std::invalid_argument);
  boost::filesystem::remove_all("just_file");
}

TEST(TestCase2, JustDir) {
  boost::filesystem::create_directory("just_dir1");
  boost::filesystem::create_directory("just_dir2");
  ASSERT_FALSE(GetTree("just_dir1", true) == GetTree("just_dir2", true));
  boost::filesystem::remove_all("just_dir1");
  boost::filesystem::remove_all("just_dir2");
}

TEST(TestCase2, DirWithFiles) {
  boost::filesystem::create_directory("just_dir1");
  auto fi = GetTree("just_dir1", false);
  boost::filesystem::ofstream file("just_dir1/just_file");
  auto se = GetTree("just_dir1", false);
  ASSERT_FALSE(fi == se);
  boost::filesystem::remove_all("just_dir1");
}

TEST(TestCase2, DirWithDirs) {
  boost::filesystem::create_directory("just_dir1");
  auto fi = GetTree("just_dir1", true);
  boost::filesystem::create_directory("just_dir1/just_dir3");
  boost::filesystem::ofstream file("just_dir1/just_file");
  auto se = GetTree("just_dir1", true);
  ASSERT_FALSE(fi == se);
  boost::filesystem::remove_all("just_dir1");

}