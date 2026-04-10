-- https://school.programmers.co.kr/learn/courses/30/lessons/59043
-- 코드를 입력하세요
SELECT AI.animal_id as ANIMAL_ID, AI.NAME as NAME
from ANIMAL_INS AI join ANIMAL_OUTS AO
on AI.animal_id = AO.animal_id
where AI.datetime > AO.datetime
order by AI.datetime asc
