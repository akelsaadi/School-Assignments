/* Ali Elsaadi G4 */
/* COSC 3380 FALL 16 Project 1 */
/* This is MY work */
/* Will NOT disseminate */

/*Create Table customer with Customer ID as PK */
CREATE TABLE Customer (
	CustomerID 		INTEGER,
	CustomerName 		varchar(30),
	CustomerAddress 	varchar(25),
	CustomerCity 			varchar(15),
	CustomerState 			char(2),
	CustomerPostalCode 		char(10),
	CustomerEmail	varchar(30),
	CustomerUsername	varchar(40),
	CustomerPassword	varchar(40),
CONSTRAINT Customer_PK	PRIMARY KEY (CustomerID));

/*Create Table SalesTerritory with SalesTerritoryID as PK */
CREATE TABLE SalesTerritory (
	SalesTerritoryID			INTEGER,
	SalesTerritoryName		VARCHAR(40),
CONSTRAINT SalesTerritory_PK PRIMARY KEY (SalesTerritoryID));

/*Create Table Orders with OrdersID as PK and CustomerID as FK */
CREATE TABLE Orders (
	OrderID 		INTEGER,
	OrderDate		char(10),
	CustomerID 		INTEGER,
CONSTRAINT Orders_PK 	PRIMARY KEY (OrderID),
CONSTRAINT Orders_FK		FOREIGN KEY (CustomerID) REFERENCES Customer(CustomerID));

/*Create Table Product Line with ProductLineID as PK */
CREATE TABLE ProductLine(
	ProductLineID	INTEGER,
	ProductLineName	char(20),
CONSTRAINT ProductLine_PK PRIMARY KEY (ProductLineID));

/*Create Table Product with ProductID as PK and ProductLineID as FK */
CREATE TABLE Product (
	ProductID		INTEGER,
	ProductName		varchar(30),
	ProductFinish	varchar(20),
	ProductStandardPrice		INTEGER,	
	ProductLineID				INTEGER,
	ProductPhoto	varchar(20),
CONSTRAINT Product_PK PRIMARY KEY (ProductID),
CONSTRAINT Product_FK FOREIGN KEY (ProductLineID) REFERENCES ProductLine(ProductLineID));


/*Create Table OrderLine with OrderID and ProductID as PK. OrderID and ProductID are FKs as well */
CREATE TABLE OrderLine (
	OrderID	INTEGER,
	ProductID 		INTEGER,
	OrderQuantity 		INTEGER,
CONSTRAINT OrderLine_PK PRIMARY KEY (OrderID, ProductID),
CONSTRAINT OrderLine_FK1 FOREIGN KEY (OrderID) REFERENCES Orders(OrderID),
CONSTRAINT OrderLine_FK2 FOREIGN KEY (ProductID) REFERENCES Product (ProductID));


/*Create Table SalesPerson with SalesPersonID as PK and SalesTerritory as FK  */
CREATE TABLE SalesPerson (
	SalesPersonID	INTEGER,
	SalesPersonName	varchar(30),
	SalesPersonTelephone varchar(30),
	SalesPersonEmail	varchar(30),
	SalesPersonUsername	varchar(30),
	SalesPersonPassword varchar(30),
	SalesTerritoryID	INTEGER,
CONSTRAINT SalesPerson_PK PRIMARY KEY (SalesPersonID),
CONSTRAINT SalesPerson_FK FOREIGN KEY (SalesTerritoryID) REFERENCES SalesTerritory(SalesTerritoryID));

/*Create Table DoesBusiness with CustomerID and SalesTerritoryID as PK. CustomerID and SalesTerritoryID are FK */
CREATE TABLE DoesBusiness (
	CustomerID		INTEGER,
	SalesTerritoryID	INTEGER,
CONSTRAINT DoesBusiness_PK PRIMARY KEY (CustomerID, SalesTerritoryID),
CONSTRAINT DoesBusiness_FK FOREIGN KEY (CustomerID) REFERENCES Customer(CustomerID),
CONSTRAINT DoesBusiness_FK1 FOREIGN KEY (SalesTerritoryID) REFERENCES SalesTerritory(SalesTerritoryID));

/*Create Table PriceUpdates with UpdatedStandardPrice as PK and ProductID as FK*/
CREATE TABLE PriceUpdates (
	PriceUpdateID 		INTEGER,
	PriceUpdateDate		varchar(15),
	OldStandardPrice		REAL,
  NewStandardPrice    REAL,
CONSTRAINT PriceUpdates_PK 	PRIMARY KEY (PriceUpdateID) );



-- Crete View 1 Product Manager
CREATE VIEW ProductManager
AS SELECT Customer.CustomerID, Customer.CustomerName, Customer.CustomerPostalCode,
Product.ProductID, Product.ProductName, Product.ProductFinish, Product.ProductStandardPrice,
ProductLine.ProductLineID, ProductLine.ProductLineName,
Orders.OrderID, Orders.OrderDate,
OrderLine.OrderQuantity
FROM Customer, Product, ProductLine, Orders, OrderLine
GROUP BY Customer.CustomerID, Customer.CustomerName, Customer.CustomerPostalCode,
Product.ProductID, Product.ProductName, Product.ProductFinish, Product.ProductStandardPrice,
ProductLine.ProductLineID, ProductLine.ProductLineName,
Orders.OrderID, Orders.OrderDate,
OrderLine.OrderQuantity;

DESCRIBE ProductManager;


SELECT *
FROM ProductManager;



-- Crete View 2 ProductLine Sales Comparision
CREATE VIEW ProductLineSalesComparision
AS SELECT ProductLine.ProductLineID, Product.ProductID, Product.ProductName,SUM(OrderLine.OrderQuantity)AS totalQuantityOrdered
FROM ProductLine, Product, OrderLine
WHERE OrderLine.ProductID = Product.ProductID
AND Product.ProductLineID = ProductLine.ProductLineID
Group BY ProductLine.PRODUCTLINEID, Product.ProductID, Product.ProductName
ORDER BY ProductLine.ProductLineID;


SELECT *
FROM ProductLineSalesComparision;




-- Create View 3 Total Value For Products 
CREATE VIEW TotalValueForProducts
AS SELECT Product.ProductID, Product.ProductStandardPrice, SUM(OrderLine.OrderQuantity) as TotalQuantity, 
SUM(OrderLine.OrderQuantity)*Product.ProductStandardPrice as TotalValue
FROM Product, OrderLine
WHERE OrderLine.ProductID = Product.ProductID
GROUP BY Product.ProductID, Product.ProductStandardPrice
ORDER BY Product.ProductID;

DESCRIBE TotalValueForProducts;

SELECT *
FROM TotalValueForProducts;



-- Create View 4 Data For Customer
CREATE VIEW DataForCustomer
AS SELECT DoesBusiness.CustomerID, DoesBusiness.SalesTerritoryID, Product.ProductID, Product.ProductName, Product.ProductStandardPrice
FROM Product, DoesBusiness, Customer, Orders, OrderLine
WHERE DoesBusiness.CustomerID = Orders.CustomerID
AND Orders.OrderID = OrderLine.OrderID
AND OrderLine.ProductID = Product.ProductID
GROUP BY DoesBusiness.CustomerID, DoesBusiness.SalesTerritoryID, Product.ProductID, Product.ProductName, Product.ProductStandardPrice
Order BY DoesBusiness.CustomerID, DoesBusiness.SalesTerritoryID, Product.ProductID, Product.ProductName, Product.ProductStandardPrice;


SELECT *
FROM DataForCustomer;




-- Create View 5 Customer By States Shipment
CREATE VIEW CustomerByStatesShipment
AS SELECT Customer.CustomerState, COUNT (Customer.CustomerState) AS numberOfCustomers
FROM Customer
GROUP BY CustomerState;


SELECT *
FROM CustomerByStatesShipment;



	

