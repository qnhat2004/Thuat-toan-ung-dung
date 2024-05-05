# Bài tập buổi 2: Tìm kiếm và sắp xếp
- Đề bài: [/Home_work/Buoi2/img](/Home_work/Buoi2/img)

## Ý tưởng bài 6:
`
Tóm tắt đề bài: Cho mảng a[] gồm n phần tử và t truy vấn, mỗi truy vấn gồm 2 số p và q đại diện cho đoạn a[p] đến a[q]. Hãy tìm số cách chia đoạn [p, q] thành 2 mảng con sao cho chênh lệch tổng 2 mảng là nhỏ nhất.
`

- Ý tưởng: Dùng đệ quy có nhớ
    - **findMinPartiton:** Giống như vét cạn, có thể tính sinh các tổng bằng cách chọn hoặc không chọn phần tử thứ i, kết quả là min của 2 cách, và lưu lại kết quả vào mảng dp -> khồng cần tính toán lại
    - **countWays:** Sau khi tìm được độ chênh lệch nhỏ nhất, đếm số cách chia sao có độ chênh lệch nhỏ nhất đó
    - **prefixSum:** Do ta cần tính tính tổng của [p, q] nhiều lần, ta chỉ cần tính trước tổng tiền tố, sau đó mỗi lần lấy tổng của [p, q] = prefix[q] - prefix[p - 1]