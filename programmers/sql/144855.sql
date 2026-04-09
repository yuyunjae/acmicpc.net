-- https://school.programmers.co.kr/learn/courses/30/lessons/144855
-- 대충 읽지 말고 자세히 읽고 풀기
-- 코드를 입력하세요
SELECT B.CATEGORY as CATEGORY, sum(BS.SALES) as TOTAL_SALES
from book_sales BS join book B
on BS.BOOK_ID = B.BOOK_ID
where to_char(BS.SALES_DATE, 'yyyymm') = '202201'
group by B.category
order by B.category asc