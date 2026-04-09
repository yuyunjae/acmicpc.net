-- https://school.programmers.co.kr/learn/courses/30/lessons/273709
-- 코드를 작성해주세요
select sum(price) as TOTAL_PRICE
from item_info
where rarity = 'LEGEND'