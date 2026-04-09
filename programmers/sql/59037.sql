-- https://school.programmers.co.kr/learn/courses/30/lessons/59037
-- 코드를 입력하세요
SELECT animal_id, name
from animal_ins
where intake_condition != 'Aged' 
-- where intake_condition <> 'Ageds'
or intake_condition is NULL
order by animal_id asc