CREATE TABLE Customer (
	CustomerID 		INTEGER,
	CustomerName 		varchar(30),
	CustomerAddress 	varchar(25),
	CustomerCity 			varchar(15),
	CustomerState 			char(2),
	CustomerPostalCode 		char(10),
	CustomerEmail	 varchar(30),
	CustomerUsername	 varchar(40),
	CustomerPassword	 varchar(40),
CONSTRAINT Customer_PK	 PRIMARY KEY (CustomerID));

/*Create Table SalesTerritory with SalesTerritoryID as PK */
CREATE TABLE SalesTerritory (
	SalesTerritoryID			 INTEGER,
	SalesTerritoryName		 VARCHAR(40),
CONSTRAINT SalesTerritory_PK  PRIMARY KEY (SalesTerritoryID));

/*Create Table Orders with OrdersID as PK and CustomerID as FK */
CREATE TABLE Orders (
	OrderID 		 INTEGER,
	OrderDate		 char(10),
	CustomerID 		 INTEGER,
CONSTRAINT Orders_PK 	 PRIMARY KEY (OrderID),
CONSTRAINT Orders_FK		 FOREIGN KEY  (CustomerID)  REFERENCES  Customer(CustomerID));

/*Create Table Product Line with ProductLineID as PK */
CREATE TABLE ProductLine(
	ProductLineID	 INTEGER,
	ProductLineName	 char(20),
CONSTRAINT ProductLine_PK  PRIMARY KEY  (ProductLineID));

/*Create Table Product with ProductID as PK and ProductLineID as FK */
CREATE TABLE Product (
	ProductID		 INTEGER,
	ProductName		 varchar(30),
	ProductFinish	 varchar(20),
	ProductStandardPrice		 INTEGER,	
	ProductLineID				 INTEGER,
	ProductPhoto	 varchar(20),
CONSTRAINT Product_PK  PRIMARY KEY  (ProductID),
CONSTRAINT Product_FK  FOREIGN KEY  (ProductLineID)  REFERENCES  ProductLine(ProductLineID));


/*Create Table OrderLine with OrderID and ProductID as PK. OrderID and ProductID are FKs as well */
CREATE TABLE OrderLine (
	OrderID	 INTEGER,
	ProductID 		 INTEGER,
	OrderQuantity 		 INTEGER,
CONSTRAINT OrderLine_PK  PRIMARY KEY (OrderID, ProductID),
CONSTRAINT OrderLine_FK1  FOREIGN KEY (OrderID) REFERENCES Orders(OrderID),
CONSTRAINT OrderLine_FK2  FOREIGN KEY (ProductID) REFERENCES Product (ProductID));


/*Create Table SalesPerson with SalesPersonID as PK and SalesTerritory as FK  */
CREATE TABLE SalesPerson (
	SalesPersonID	 INTEGER,
	SalesPersonName	 varchar(30),
	SalesPersonTelephone  varchar(30),
	SalesPersonEmail	 varchar(30),
	SalesPersonUsername	 varchar(30),
	SalesPersonPassword  varchar(30),
	SalesTerritoryID	 INTEGER,
CONSTRAINT SalesPerson_PK  PRIMARY KEY (SalesPersonID),
CONSTRAINT SalesPerson_FK FOREIGN KEY (SalesTerritoryID) REFERENCES SalesTerritory(SalesTerritoryID));

/*Create Table DoesBusiness with CustomerID and SalesTerritoryID as PK. CustomerID and SalesTerritoryID are FK */
CREATE TABLE DoesBusiness (
	CustomerID		 INTEGER,
	SalesTerritoryID	 INTEGER,
CONSTRAINT DoesBusiness_PK PRIMARY KEY (CustomerID, SalesTerritoryID),
CONSTRAINT DoesBusiness_FK FOREIGN KEY (CustomerID) REFERENCES Customer(CustomerID),
CONSTRAINT DoesBusiness_FK1 FOREIGN KEY (SalesTerritoryID) REFERENCES SalesTerritory(SalesTerritoryID));

/*Create Table PriceUpdates with UpdatedStandardPrice as PK and ProductID as FK*/
CREATE TABLE PriceUpdates (
	PriceUpdateID 		 INTEGER,
	PriceUpdateDate		 varchar(15),
	OldStandardPrice		 REAL,
  NewStandardPrice     REAL,
CONSTRAINT PriceUpdates_PK 	 PRIMARY KEY (PriceUpdateID) );



/* Inserting values into table customer*/
INSERT INTO CUSTOMER (CustomerID, CustomerName, CustomerAddress, CustomerCity, CustomerState, CustomerPostalCode) Values
(1, 'Contemporary Casuals', '1355 S Hines Blvd', 'Gainesville', 'FL', '32601-2871');
INSERT INTO CUSTOMER (CustomerID, CustomerName, CustomerAddress, CustomerCity, CustomerState, CustomerPostalCode) Values
(2, 'Value Furnitures', '15145 S.W. 17th St.', 'Plano', 'TX', '75094-7734');
INSERT INTO CUSTOMER (CustomerID, CustomerName, CustomerAddress, CustomerCity, CustomerState, CustomerPostalCode, CustomerEmail, CustomerUsername, CustomerPassword) Values
(3, 'Home Furnishings', '1900 Allard Ave', 'Albany', 'NY', '12209-1125',  'homefurnishings@gmail.com', 'CUSTOMER1', 'CUSTOMER1#');
INSERT INTO CUSTOMER (CustomerID, CustomerName, CustomerAddress, CustomerCity, CustomerState, CustomerPostalCode) Values
(4, 'Eastern Furniture', '1925 Beltline Rd.', 'Carteret', 'NJ', '07008-3188');
INSERT INTO CUSTOMER (CustomerID, CustomerName, CustomerAddress, CustomerCity, CustomerState, CustomerPostalCode) Values
(5, 'Impressions', '5585 Westcott Ct.', 'Sacramento', 'CA', '94206-4056');
INSERT INTO CUSTOMER (CustomerID, CustomerName, CustomerAddress, CustomerCity, CustomerState, CustomerPostalCode) Values
(6, 'Furniture Gallery', '325 Flatiron Dr.', 'Boulder', 'CO', '80514-4432');
INSERT INTO CUSTOMER (CustomerID, CustomerName, CustomerAddress, CustomerCity, CustomerState, CustomerPostalCode) Values
(7, 'New Furniture', 'Palace Ave', 'Farmington', 'NM', '');
INSERT INTO CUSTOMER (CustomerID, CustomerName, CustomerAddress, CustomerCity, CustomerState, CustomerPostalCode) Values
(8, 'Dunkins Furniture', '7700 Main St', 'Syracuse', 'NY', '31590');
INSERT INTO CUSTOMER (CustomerID, CustomerName, CustomerAddress, CustomerCity, CustomerState, CustomerPostalCode) Values
(9, 'A Carpet', '434 Abe Dr', 'Rome', 'NY', '13440');
INSERT INTO CUSTOMER (CustomerID, CustomerName, CustomerAddress, CustomerCity, CustomerState, CustomerPostalCode) Values
(12, 'Flanigan Furniture', 'Snow Flake Rd', 'Ft Walton Beach', 'FL', '32548');
INSERT INTO CUSTOMER (CustomerID, CustomerName, CustomerAddress, CustomerCity, CustomerState, CustomerPostalCode) Values
(13, 'Ikards', '1011 S. Main St', 'Las Cruces', 'NM', '88001');
INSERT INTO CUSTOMER (CustomerID, CustomerName, CustomerAddress, CustomerCity, CustomerState, CustomerPostalCode) Values
(14, 'Wild Bills', 'Four Horse Rd', 'Oak Brook', 'Il', '60522');
INSERT INTO CUSTOMER (CustomerID, CustomerName, CustomerAddress, CustomerCity, CustomerState, CustomerPostalCode) Values
(15, 'Janets Collection', 'Janet Lane', 'Virginia Beach', 'VA', '10012');
INSERT INTO CUSTOMER (CustomerID, CustomerName, CustomerAddress, CustomerCity, CustomerState, CustomerPostalCode) Values
(16, 'ABC Furniture Co.', '152 Geramino Drive', 'Rome', 'NY', '13440');

Select * From Customer;

/*Inserting values into SalesTerritory Table */
INSERT INTO SalesTerritory (SalesTerritoryID, SalesTerritoryName) Values
(1, 'SouthEast');
INSERT INTO SalesTerritory (SalesTerritoryID, SalesTerritoryName) Values
(2, 'SouthWest');
INSERT INTO SalesTerritory (SalesTerritoryID, SalesTerritoryName) Values
(3, 'NorthEast');
INSERT INTO SalesTerritory (SalesTerritoryID, SalesTerritoryName) Values
(4, 'NorthWest');
INSERT INTO SalesTerritory (SalesTerritoryID, SalesTerritoryName) Values
(5, 'Central');

SELECT * FROM SalesTerritory;

/*Inserting values into DOESBUSINESS Table */
INSERT INTO DOESBUSINESS (CustomerID, SALESTERRITORYID) VALUES
(1, 1);
INSERT INTO DOESBUSINESS (CustomerID, SALESTERRITORYID) VALUES
(2, 2);
INSERT INTO DOESBUSINESS (CustomerID, SALESTERRITORYID) VALUES
(3, 3);
INSERT INTO DOESBUSINESS (CustomerID, SALESTERRITORYID) VALUES
(4, 4);
INSERT INTO DOESBUSINESS (CustomerID, SALESTERRITORYID) VALUES
(5, 5);
INSERT INTO DOESBUSINESS (CustomerID, SALESTERRITORYID) VALUES
(6, 1);
INSERT INTO DOESBUSINESS (CustomerID, SALESTERRITORYID) VALUES
(7, 2);
Select * FROM DOESBUSINESS;

/* Inserting values into SalesPerson */
INSERT INTO SALESPERSON (SalesPersonID, SalesPersonName, SalesPersonTelephone, SalesPersonEmail, SalesPersonUsername, SalesPersonPassword, SalesTerritoryID) VALUES
(1, 'Doug Henny', '8134445555', 'salesperson@gmail.com', 'SALESPERSON', 'SALESPERSON#',1);
INSERT INTO SALESPERSON (SalesPersonID, SalesPersonName, SalesPersonTelephone, SalesPersonEmail, SalesPersonUsername, SalesPersonPassword, SalesTerritoryID) VALUES
(2, 'Robert Lewis', '8139264006', '', '', '', 2);
INSERT INTO SALESPERSON (SalesPersonID, SalesPersonName, SalesPersonTelephone, SalesPersonEmail, SalesPersonUsername, SalesPersonPassword, SalesTerritoryID) VALUES
(3, 'William Strong', '5053821212', '', '', '', 3);
INSERT INTO SALESPERSON (SalesPersonID, SalesPersonName, SalesPersonTelephone, SalesPersonEmail, SalesPersonUsername, SalesPersonPassword, SalesTerritoryID) VALUES
(4, 'Julie Dawson', '4355346677', '', '', '', 4);
INSERT INTO SALESPERSON (SalesPersonID, SalesPersonName, SalesPersonTelephone, SalesPersonEmail, SalesPersonUsername, SalesPersonPassword, SalesTerritoryID) VALUES
(5, 'Jacob Winslow', '2238973498', '', '', '', 5);
SELECT * FROM SALESPERSON;

/*Inserting values into PRODUCTLINE */
INSERT INTO PRODUCTLINE(ProductLineID, ProductLineName) VALUES
(1, 'Cherry Tree');
INSERT INTO PRODUCTLINE(ProductLineID, ProductLineName) VALUES
(2, 'Scandinavia');
INSERT INTO PRODUCTLINE(ProductLineID, ProductLineName) VALUES
(3, 'Country Look');
SELECT * FROM PRODUCTLINE;

/*Inserting values into PRODUCT */
INSERT INTO PRODUCT (ProductID, ProductName, ProductFinish, ProductStandardPrice, ProductLineID, ProductPhoto)	VALUES 
(1, 'End Table', 'Cherry', 175, 1, 'table.jpg');
INSERT INTO PRODUCT (ProductID, ProductName, ProductFinish, ProductStandardPrice, ProductLineID, ProductPhoto)	VALUES
(2, 'Coffee Table', 'Natural Ash', 200, 2, '');
INSERT INTO PRODUCT (ProductID, ProductName, ProductFinish, ProductStandardPrice, ProductLineID, ProductPhoto)	VALUES
(3, 'Computer Desk', 'Natural Ash', 375, 2, '');
INSERT INTO PRODUCT (ProductID, ProductName, ProductFinish, ProductStandardPrice, ProductLineID, ProductPhoto)	VALUES
(4, 'Entertainment Center', 'Natural Maple', 650, 3, '');
INSERT INTO PRODUCT (ProductID, ProductName, ProductFinish, ProductStandardPrice, ProductLineID, ProductPhoto)	VALUES
(5, 'Writers Desk', 'Cherry', 325, 1, '');
INSERT INTO PRODUCT (ProductID, ProductName, ProductFinish, ProductStandardPrice, ProductLineID, ProductPhoto)	VALUES
(6, '8-Drawer Desk', 'White Ash', 750, 2, '');
INSERT INTO PRODUCT (ProductID, ProductName, ProductFinish, ProductStandardPrice, ProductLineID, ProductPhoto)	VALUES
(7, 'Dining Table', 'Natural Ash', 800, 2, '');
INSERT INTO PRODUCT (ProductID, ProductName, ProductFinish, ProductStandardPrice, ProductLineID, ProductPhoto)	VALUES
(8, 'Computer Desk', 'Walnut', 250, 3, '');
SELECT * FROM PRODUCT;


/*Inserting values into ORDERS */
INSERT INTO ORDERS(OrderID, OrderDate, CustomerID) VALUES
(1001, '21/Aug/16', 1);
INSERT INTO ORDERS(OrderID, OrderDate, CustomerID) VALUES
(1002, '21/Jul/16', 8);
INSERT INTO ORDERS(OrderID, OrderDate, CustomerID) VALUES
(1003, '22/ Aug/16', 15);
INSERT INTO ORDERS(OrderID, OrderDate, CustomerID) VALUES
(1004, '22/Oct/16', 5);
INSERT INTO ORDERS(OrderID, OrderDate, CustomerID) VALUES
(1005, '24/Jul/16', 3);
INSERT INTO ORDERS(OrderID, OrderDate, CustomerID) VALUES
(1006, '24/Oct/16', 2);
INSERT INTO ORDERS(OrderID, OrderDate, CustomerID) VALUES
(1007, '27/ Aug/16', 5);
INSERT INTO ORDERS(OrderID, OrderDate, CustomerID) VALUES
(1008, '30/Oct/16', 12);
INSERT INTO ORDERS(OrderID, OrderDate, CustomerID) VALUES
(1009, '05/Nov/16', 4);
INSERT INTO ORDERS(OrderID, OrderDate, CustomerID) VALUES
(1010, '05/Nov/16', 1);
SELECT * FROM ORDERS;

/*Inserting Values into ORDERLINE*/
INSERT INTO ORDERLINE(OrderID, ProductID, OrderQuantity) VALUES
(1001, 1, 2);
INSERT INTO ORDERLINE(OrderID, ProductID, OrderQuantity) VALUES
(1001, 2, 2);
INSERT INTO ORDERLINE(OrderID, ProductID, OrderQuantity) VALUES
(1001, 4, 1);
INSERT INTO ORDERLINE(OrderID, ProductID, OrderQuantity) VALUES
(1002, 3, 5);
INSERT INTO ORDERLINE(OrderID, ProductID, OrderQuantity) VALUES
(1003, 3, 3);
INSERT INTO ORDERLINE(OrderID, ProductID, OrderQuantity) VALUES
(1004, 6, 2);
INSERT INTO ORDERLINE(OrderID, ProductID, OrderQuantity) VALUES
(1004, 8, 2);
INSERT INTO ORDERLINE(OrderID, ProductID, OrderQuantity) VALUES
(1005, 4, 4);
INSERT INTO ORDERLINE(OrderID, ProductID, OrderQuantity) VALUES
(1006, 4, 1);
INSERT INTO ORDERLINE(OrderID, ProductID, OrderQuantity) VALUES
(1006, 5, 2);
INSERT INTO ORDERLINE(OrderID, ProductID, OrderQuantity) VALUES
(1006, 7, 2);
INSERT INTO ORDERLINE(OrderID, ProductID, OrderQuantity) VALUES
(1007, 1, 3);
INSERT INTO ORDERLINE(OrderID, ProductID, OrderQuantity) VALUES
(1007, 2, 2);
INSERT INTO ORDERLINE(OrderID, ProductID, OrderQuantity) VALUES
(1008, 3, 3);
INSERT INTO ORDERLINE(OrderID, ProductID, OrderQuantity) VALUES
(1008, 8, 3);
INSERT INTO ORDERLINE(OrderID, ProductID, OrderQuantity) VALUES
(1009, 4, 2);
INSERT INTO ORDERLINE(OrderID, ProductID, OrderQuantity) VALUES
(1009, 7, 3);
INSERT INTO ORDERLINE(OrderID, ProductID, OrderQuantity) VALUES
(1010, 8, 10);
SELECT * FROM ORDERLINE;


/* Select Statement for the query in php */

select p.productid, p.productfinish, sum(ol.orderquantity)
    from product p, orderline ol
    where p.productid = ol.productid group by p.productid, p.productfinish
    order by p.productid