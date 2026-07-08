# Write your MySQL query statement below
SELECT (SELECT DISTINCT salary
from Employee
order by salary DESC 
limit 1 offset 1 )SecondHighestSalary
