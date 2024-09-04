# Write your MySQL query statement below
select ROUND(AVG(IF(d.order_date = d.customer_pref_delivery_date,1,0))*100,2)
AS immediate_percentage
from Delivery d left join
(select customer_id, MIN(order_date) as first_order_date
from Delivery
group by customer_id) f
on d.customer_id = f.customer_id
where d.order_date = f.first_order_date;