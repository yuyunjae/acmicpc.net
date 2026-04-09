-- https://school.programmers.co.kr/learn/courses/30/lessons/293261
-- 중첩쿼리 & join 연산 공부하기!
-- 코드를 작성해주세요
select fi.id as ID, fni.fish_name as FISH_NAME, fi.length as LENGTH
from fish_info fi join fish_name_info fni
on fi.fish_type = fni.fish_type
join (select A.fish_type, max(length) as max_length
     from fish_info A
     group by A.fish_type
     ) m
on fi.fish_type = m.fish_type
where fi.length = m.max_length
order by fi.id asc