-- https://school.programmers.co.kr/learn/courses/30/lessons/59415
-- 테이블에 별칭을 부여할 때는 as 를 안쓴다는 것 기억하기!!
-- 코드를 입력하세요
SELECT datetime
from (
    Select A.datetime
     from animal_ins A
     order by A.datetime desc
)
where rownum = 1