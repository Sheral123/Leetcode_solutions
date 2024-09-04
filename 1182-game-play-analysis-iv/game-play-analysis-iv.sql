# Write your MySQL query statement below
select ROUND(COUNT(DISTINCT t.player_id)/COUNT(DISTINCT a.player_id),2)
AS fraction
from Activity a
left join
(select player_id, MIN(event_date) as fld
from Activity 
group by player_id) t
on a.player_id = t.player_id
and DATE_SUB(a.event_date,INTERVAL 1 DAY) = t.fld;
