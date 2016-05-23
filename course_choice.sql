/*
Navicat MySQL Data Transfer

Source Server         : 127.0.0.1
Source Server Version : 50622
Source Host           : localhost:3306
Source Database       : course_choice

Target Server Type    : MYSQL
Target Server Version : 50622
File Encoding         : 65001

Date: 2016-05-23 14:18:14
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for `course`
-- ----------------------------
DROP TABLE IF EXISTS `course`;
CREATE TABLE `course` (
  `course_id` char(11) NOT NULL,
  `name` char(20) DEFAULT NULL,
  `department` char(20) DEFAULT NULL,
  `score` char(10) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of course
-- ----------------------------
INSERT INTO `course` VALUES ('1001', '计算机', '算计', '1.5');
INSERT INTO `course` VALUES ('1002', '数学', '数学', '1.5');

-- ----------------------------
-- Table structure for `course_tech`
-- ----------------------------
DROP TABLE IF EXISTS `course_tech`;
CREATE TABLE `course_tech` (
  `sec_id` char(11) NOT NULL,
  `course_id` char(11) NOT NULL,
  `tech_id` char(11) NOT NULL,
  `time_slod_id` char(11) NOT NULL,
  `place` char(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of course_tech
-- ----------------------------
INSERT INTO `course_tech` VALUES ('1002', '1001', '1005', '1000', '浙江大学');
INSERT INTO `course_tech` VALUES ('1001', '1002', '1040', '1001', '浙江大学');

-- ----------------------------
-- Table structure for `student`
-- ----------------------------
DROP TABLE IF EXISTS `student`;
CREATE TABLE `student` (
  `s_id` char(11) NOT NULL,
  `name` char(20) NOT NULL,
  `psword` char(20) NOT NULL,
  `grade` char(20) NOT NULL,
  `major` char(20) NOT NULL,
  `department` char(20) NOT NULL,
  PRIMARY KEY (`s_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of student
-- ----------------------------
INSERT INTO `student` VALUES ('1001', '杨奕辉', '123456', '14', '计算机', '计算机');

-- ----------------------------
-- Table structure for `stu_course`
-- ----------------------------
DROP TABLE IF EXISTS `stu_course`;
CREATE TABLE `stu_course` (
  `sec_id` char(11) NOT NULL,
  `s_id` char(11) NOT NULL,
  `grade` char(20) DEFAULT NULL,
  `year` char(10) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of stu_course
-- ----------------------------
INSERT INTO `stu_course` VALUES ('1001', '1001', null, '1555');
INSERT INTO `stu_course` VALUES ('1001', '1002', '', '1001');
INSERT INTO `stu_course` VALUES ('1002', '1001', null, '2016');
