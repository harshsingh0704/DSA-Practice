# Write your MySQL query statement below

SELECT (
SELECT num 
from MyNumbers
GROUP BY num
HAVING COUNT(*) = 1
ORDER BY num DESC
limit 1
) AS num 
