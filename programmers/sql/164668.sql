-- https://school.programmers.co.kr/learn/courses/30/lessons/164668
-- having 절에 들어가야하는지, where 절에 들어가야하는지 잘 구분하기  
-- 코드를 입력하세요
SELECT UGU.USER_ID as USER_ID, UGU.NICKNAME as NICKNAME, UGB.TOTAL_SALES as TOTAL_SALES
from USED_GOODS_USER UGU 
join (select writer_id, sum(price) as TOTAL_SALES
     from used_goods_board
     where status = 'DONE'
     group by writer_id ) UGB
on UGB.writer_id = UGU.user_id
where UGB.TOTAL_SALES >= 700000
order by UGB.TOTAL_SALES
