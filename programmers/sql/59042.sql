-- https://school.programmers.co.kr/learn/courses/30/lessons/59042
-- table 선언에서 as 쓰지말기
-- order by 까먹지 말기
-- 코드를 입력하세요
-- SELECT AO.animal_id as ANIMAL_ID, AO.name as NAME
-- from animal_outs AO
-- where AO.animal_id not in (select AI.animal_id
--                           from animal_ins AI)
--                           -- where AO.animal_id = AI.animal_id)
-- order by AO.animal_id asc


SELECT AO.animal_id as ANIMAL_ID, AO.name as NAME
from animal_outs AO
where not exists (select AI.animal_id
                          from animal_ins AI
                 where AO.animal_id = ai.animal_id)
order by AO.animal_id asc