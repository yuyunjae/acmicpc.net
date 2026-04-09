-- https://school.programmers.co.kr/learn/courses/30/lessons/131120
-- 꼼꼼히 보기! '여성' 과 출력되는 column의 이름을 잘보기(바꿔줘야하는지 등..)
-- 코드를 입력하세요
SELECT MEMBER_ID, MEMBER_NAME, GENDER, to_char(member_profile.DATE_OF_BIRTH, 'yyyy-mm-dd') as DATE_OF_BIRTH
from MEMBER_profile
where to_char(member_profile.date_of_birth, 'mm') = '03' and tlno is not null and gender = 'W'
order by member_id asc