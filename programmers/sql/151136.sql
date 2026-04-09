-- https://school.programmers.co.kr/learn/courses/30/lessons/151136?language=oracle
-- 코드를 입력하세요
SELECT round(sum(daily_fee) / count(*), 0) as AVERAGE_FEE
from car_rental_company_car
where car_type = 'SUV'