# Write your MySQL query statement below
select ROUND(AVG(IF(order_date = customer_pref_delivery_date,1,0))*100,2)
AS immediate_percentage
from Delivery
where (customer_id,order_date) in
(select customer_id, MIN(order_date) as first_order_date
from Delivery
group by customer_id);