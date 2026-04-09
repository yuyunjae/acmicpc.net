-- https://school.programmers.co.kr/learn/courses/30/lessons/132203
-- 코드를 입력하세요
SELECT dr_name, dr_id, mcdp_cd, to_char(hire_ymd, 'yyyy-mm-dd') as hire_ymd
from doctor
where mcdp_cd = 'CS' or mcdp_cd = 'GS'
order by hire_ymd desc, dr_name asc