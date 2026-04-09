-- https://school.programmers.co.kr/learn/courses/30/lessons/131123
-- 코드를 입력하세요
SELECT R.food_type as food_type, R.rest_id as rest_id, R.rest_name as rest_name, R.favorites as favorites
from rest_info R join (
select max(RE.favorites) as max_favorites, RE.food_type
from rest_info RE
group by RE.food_type) RI
on R.food_type = RI.food_type and R.favorites = RI.max_favorites
order by R.food_type desc
