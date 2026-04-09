-- https://school.programmers.co.kr/learn/courses/30/lessons/59038
-- 코드를 입력하세요
SELECT datetime
from (select A.datetime
      from animal_ins A
      order by A.datetime asc)
where rownum = 1