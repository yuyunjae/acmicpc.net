-- https://school.programmers.co.kr/learn/courses/30/lessons/59405
-- 코드를 입력하세요

-- SELECT A.name
-- from (select name
--      from animal_ins
--      order by datetime asc) A
-- where rownum < 2;


SELECT name
from animal_ins
order by datetime asc
fetch First 1 rows only

