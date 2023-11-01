DROP SCHEMA IF EXISTS `final`;

CREATE SCHEMA `final`;

USE `final`;

SET FOREIGN_KEY_CHECKS = 0;

DROP TABLE IF EXISTS `student_detail`;

CREATE TABLE `student_detail` (
  `detail_id` int(11) NOT NULL AUTO_INCREMENT,
  `punch_line` varchar(128) DEFAULT NULL,
  `hobby` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`detail_id`)
) ENGINE=InnoDB AUTO_INCREMENT=1 DEFAULT CHARSET=latin1;

DROP TABLE IF EXISTS `student`;

CREATE TABLE `student` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(128) DEFAULT NULL,
  `detail_id` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `FK_DETAIL_idx` (`detail_id`),
  CONSTRAINT `FK_DETAIL` FOREIGN KEY (`detail_id`) REFERENCES `student_detail` (`detail_id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB AUTO_INCREMENT=1 DEFAULT CHARSET=latin1;

SET FOREIGN_KEY_CHECKS = 1;

