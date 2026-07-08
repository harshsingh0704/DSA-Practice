# Write your MySQL query statement below
SELECT name, bonus 
FROM Employee
Left join Bonus 
ON Employee.empId=Bonus.empId
where bonus<1000
OR bonus IS NULL;