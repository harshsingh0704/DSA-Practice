DELETE P1
from Person P1,Person P2
where P1.email=P2.email 
 AND p1.id > p2.id;