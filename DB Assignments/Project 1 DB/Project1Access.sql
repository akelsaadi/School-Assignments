CREATE TABLE Customer (
	Customer_ID 		INTEGER Primary Key,
	Customer_Name 		varchar(30),
	Customer_Address 	varchar(25),
	City 			varchar(15),
	State 			char(2),
	Postal_code 		char(10),
	Customer_Email 	varchar(30),
	Customer_Username 	varchar(40),
	Customer_Password	 varchar(40));
	
CREATE TABLE Product (
	ProductID		 INTEGER Primary Key,
	ProductName		 varchar(30),
	ProductFinish 	varchar(20),
	ProductStandardPrice 		INTEGER,
	ProductPhoto 	varchar(20),
	ProductLineID 				INTEGER REFERENCES ProductLine (ProductLineID));

CREATE TABLE Orders (
	Orders_ID 		INTEGER Primary Key,
	Orders_Date 		char(10),
	Customer_ID 		INTEGER References Customer(Customer_ID));

CREATE TABLE OrderLine (
	OrderQuantity	 INTEGER Primary Key,
	ProductID 		INTEGER REFERENCES Product (ProductID),
	Orders_ID 		INTEGER REFERENCES Orders(Orders_ID));

CREATE Table SalesTerritory(
SalesTerritoryID Integer Primary Key,
SalesTerritoryName varchar(40));


CREATE TABLE SalesPerson (
	SalesPersonID 	INTEGER Primary Key,
	SalesPersonName 	varchar(30),
	SalesPersonTelephone varchar(30),
	SalesPersonEmail	 varchar(30),
	SalesPersonUsername 	varchar(30),
	SalesPersonPassword varchar(30),
	SalesTerritoryID 	INTEGER References SalesTerritory(SalesTerritoryID));

CREATE TABLE PriceUpdates (
	UpdatedStandardPrice	 INTEGER Primary Key,
	PriceUpdateDate 			char(10),
	ProductID 				INTEGER References Product(productID));

CREATE TABLE DoesBusiness (
	Customer_ID 		INTEGER References Customer (Customer_ID),
	SalesTerritoryID 	INTEGER References SalesTerritory (SalesTerritoryID));


CREATE TABLE ProductLine(
	ProductLineID 	INTEGER Primary Key,
	ProductLineName	 char(10));	