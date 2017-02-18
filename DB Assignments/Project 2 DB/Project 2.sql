/* Ali Elsaadi G4 */
/* COSC 3380 FALL 16 Project 2 */
/* This is MY work */
/* Will NOT disseminate */

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

/*Selecting products that have a standard price of less than 275 */
SELECT PRODUCTNAME, PRODUCTSTANDARDPRICE FROM PRODUCT
  WHERE PRODUCTSTANDARDPRICE < 275;

/*Listing the unit price, product name, and product ID for all products in the Product table */
 SELECT PRODUCTSTANDARDPRICE, PRODUCTNAME, PRODUCTID
   FROM PRODUCT;

/*the average standard price for all products in inventory */
 SELECT AVG(PRODUCTSTANDARDPRICE)  FROM PRODUCT;
 
 /*How many different items were ordered on order number 1004 */
SELECT COUNT (*)
   FROM ORDERLINE
     WHERE OrderID = 1004;
	 
/* Orders placed before 2010-10-24 */
SELECT *
FROM Orders
WHERE OrderDate >= '2010-10-24';	 
	 
/*Furniture that isn’t made of cherry */
 SELECT PRODUCTNAME, PRODUCTFINISH
   FROM PRODUCT
     WHERE PRODUCTFINISH != 'Cherry';
	 
	 
/*Product name, finish, and standard price for all desks and all tables that cost more than $300 in the product table */

SELECT ProductName, ProductFinish, ProductStandardPrice
FROM Product
WHERE ProductStandardPrice > 300;
	 
/*products in the Product table have a standard price between $ 200 and $300 */
SELECT PRODUCTNAME, PRODUCTSTANDARDPRICE
  FROM PRODUCT
    WHERE PRODUCTSTANDARDPRICE BETWEEN 200 AND 300;

/*all customers in the Customer table whose address is Florida, Texas, California, or Hawaii.
customers ordered alphabetically by CustomerState and alphabetically by customer within each CustomerState.  */
SELECT CustomerName, CustomerCity, CustomerState
  FROM CUSTOMER
    WHERE CustomerState IN ('FL', 'TX', 'CA', 'HI')
      ORDER BY CustomerState, CustomerName;

/*Count the number of customers with addresses in each CustomerState to which we ship*/
SELECT CustomerState, COUNT (CustomerState)
  FROM CUSTOMER 
    GROUP BY CustomerState; 	  
	  
	  
/*Count the number of customers with addresses in each CustomerState to which we ship. List the cities by CustomerState. */
 SELECT CustomerState, CustomerCity, COUNT (CustomerCity)
   FROM CUSTOMER
     GROUP BY CustomerState, CustomerCity;	  
	 
/*only CustomerStates with more than one customer*/
SELECT CustomerState, COUNT (CustomerState)
  FROM CUSTOMER
    GROUP BY CustomerState
      HAVING COUNT (CustomerState) > 1;

/*In alphabetical order, the product finish and the average standard price for each finish for selected finishes
that have an average standard price less than 750. */
SELECT PRODUCTFINISH, AVG (PRODUCTSTANDARDPRICE)
   FROM PRODUCT
       GROUP BY PRODUCTFINISH
         HAVING AVG (PRODUCTSTANDARDPRICE) < 750
           ORDER BY PRODUCTFINISH;

/*total value of orders placed for each furniture product*/	
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