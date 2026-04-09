-- https://school.programmers.co.kr/learn/courses/30/lessons/131535
-- -- 코드를 입력하세요
-- SELECT count(*)
-- from user_info
-- where to_char(joined, 'yyyy') = '2021' 
-- and age >= 20 and age <= 29 and age is not null

-- select count(*) as USERS
-- from user_info
-- where joined >= to_date('2021-01-01', 'yyyy-mm-dd') and joined <= to_date('2021-12-31', 'yyyy-mm-dd') and age >= 20 and age <= 29;


-- select count(*) as USERS
-- from user_info
-- where joined >= to_date('20210101', 'yyyymmdd') and joined <= to_date('20211231', 'yyyymmdd') and age >= 20 and age <= 29;


SELECT COUNT(*) AS USERS
FROM USER_INFO
WHERE JOINED >= DATE '2021-01-01'
  AND JOINED <  DATE '2022-01-01'
  AND AGE BETWEEN 20 AND 29;