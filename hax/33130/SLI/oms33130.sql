-- MySQL dump 10.13  Distrib 5.7.26, for Linux (x86_64)
--
-- Host: localhost    Database: oms33130
-- ------------------------------------------------------
-- Server version	5.7.26-0ubuntu0.16.04.1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `category`
--

DROP TABLE IF EXISTS `category`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `category` (
  `cat_id` int(11) NOT NULL,
  `cat_name` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`cat_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `category`
--

LOCK TABLES `category` WRITE;
/*!40000 ALTER TABLE `category` DISABLE KEYS */;
INSERT INTO `category` VALUES (1,'Colors'),(2,'Erasers'),(3,'Sharpeners'),(4,'Pencil'),(5,'Pen'),(6,'Exam Pads'),(7,'Pencil Box'),(8,'Calculators'),(9,'Notebooks'),(10,'Files'),(11,'Folders'),(12,'Scissors'),(13,'Glue'),(14,'Tape'),(15,'Staplers'),(16,'Punching machine'),(17,'Tools'),(18,'Printing suplies'),(19,'School suplies'),(20,'Boards');
/*!40000 ALTER TABLE `category` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `customer`
--

DROP TABLE IF EXISTS `customer`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `customer` (
  `cust_id` int(11) NOT NULL,
  `fname` varchar(15) NOT NULL,
  `lname` varchar(15) NOT NULL,
  `email` varchar(25) NOT NULL,
  `street` varchar(15) NOT NULL,
  `city` varchar(15) NOT NULL DEFAULT 'Pune',
  `state` varchar(15) NOT NULL,
  PRIMARY KEY (`cust_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `customer`
--

LOCK TABLES `customer` WRITE;
/*!40000 ALTER TABLE `customer` DISABLE KEYS */;
INSERT INTO `customer` VALUES (1,'Kunal','Sachdev','kunalsachdev456@gmail.com','devlali','nashik','Maharashtra'),(2,'Animesh','Landge','anni.landge@gmail.com','borivali','mumbai','Maharashtra'),(3,'Yash','Jeswani','Yashjeswani2420@gmail.com','Dhankawadi','Pune','Maharashtra'),(4,'Soham','Kotalwar','sohamkotalwar@gmail.com','kalamandir','nanded','Maharashtra');
/*!40000 ALTER TABLE `customer` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `orders`
--

DROP TABLE IF EXISTS `orders`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `orders` (
  `or_id` int(11) NOT NULL,
  `cust_no` int(11) DEFAULT NULL,
  `or_date` date DEFAULT NULL,
  `total_amt` int(11) NOT NULL,
  PRIMARY KEY (`or_id`),
  KEY `fk_cust` (`cust_no`),
  CONSTRAINT `orders_ibfk_1` FOREIGN KEY (`cust_no`) REFERENCES `customer` (`cust_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `orders`
--

LOCK TABLES `orders` WRITE;
/*!40000 ALTER TABLE `orders` DISABLE KEYS */;
INSERT INTO `orders` VALUES (1,1,'2019-03-10',70),(2,1,'2019-07-10',95),(3,2,'2019-04-10',580),(4,3,'2019-05-10',1430),(5,4,'2019-06-11',184);
/*!40000 ALTER TABLE `orders` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `product`
--

DROP TABLE IF EXISTS `product`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `product` (
  `cat_id` int(11) DEFAULT NULL,
  `p_id` int(11) NOT NULL,
  `p_name` varchar(20) DEFAULT NULL,
  `unit_price` int(11) NOT NULL,
  `stock` int(11) DEFAULT NULL,
  PRIMARY KEY (`p_id`),
  KEY `cat_id` (`cat_id`),
  CONSTRAINT `product_ibfk_1` FOREIGN KEY (`cat_id`) REFERENCES `category` (`cat_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `product`
--

LOCK TABLES `product` WRITE;
/*!40000 ALTER TABLE `product` DISABLE KEYS */;
INSERT INTO `product` VALUES (1,1,'Crayons',30,100),(1,2,'Water colors',50,50),(1,3,'Pencil colors',20,200),(2,4,'big eraser',10,100),(2,5,'small eraser',5,100),(3,6,'Dust sharpener',30,200),(3,7,'Non Dust Sharpener',5,200),(4,8,'With eraser',5,300),(4,9,'without eraser',2,100),(5,10,'Gel pen',5,200),(5,11,'Ball pen',5,300),(5,12,'Ink Pen',20,500),(6,13,'Exam Pad',150,100),(6,14,'Normal Pad',100,500),(7,15,'Pouch',30,100),(7,16,'Geometry Box',100,300),(8,17,'Scientific',1000,200),(8,18,'Normal',100,100),(9,19,'Four line ',20,300),(9,20,'Single line',30,100),(9,21,'Square box',20,500),(10,22,'Office file',50,300),(10,23,'Project file',20,500),(11,24,'Single',20,500),(11,25,'Multiple',50,100),(12,26,'Paper',30,500),(12,27,'Cloth',40,100),(13,28,'Fevicol',10,100),(13,29,'Hot glue',100,100),(13,30,'Wood glue',30,500),(14,31,'Single sided',10,300),(14,32,'Double sided',20,500),(15,33,'Small',20,500),(15,34,'Big',100,500),(16,35,'Small',50,500),(16,36,'Big',100,500),(17,37,'rounder',50,300),(17,38,'Divider',20,500),(18,39,'Ink',100,200),(18,40,'Paper',50,100),(19,41,'School bag',400,100),(19,42,'School books',1000,100),(20,43,'Black',300,100),(20,44,'White',100,500);
/*!40000 ALTER TABLE `product` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `selects`
--

DROP TABLE IF EXISTS `selects`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `selects` (
  `or_id` int(11) NOT NULL,
  `p_id` int(11) NOT NULL,
  `quantity` int(11) DEFAULT NULL,
  `total_amount` int(11) DEFAULT NULL,
  PRIMARY KEY (`p_id`,`or_id`),
  KEY `or_id` (`or_id`),
  CONSTRAINT `selects_ibfk_1` FOREIGN KEY (`p_id`) REFERENCES `product` (`p_id`),
  CONSTRAINT `selects_ibfk_2` FOREIGN KEY (`or_id`) REFERENCES `orders` (`or_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `selects`
--

LOCK TABLES `selects` WRITE;
/*!40000 ALTER TABLE `selects` DISABLE KEYS */;
INSERT INTO `selects` VALUES (1,1,2,60),(5,1,6,180),(1,4,1,10),(2,7,1,5),(5,9,2,4),(4,10,1,5),(2,20,3,90),(3,21,4,80),(4,43,5,1500),(3,44,5,500);
/*!40000 ALTER TABLE `selects` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2019-07-24 15:52:58
