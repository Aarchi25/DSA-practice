WITH borrow_count AS (
    SELECT 
        book_id,
        COUNT(*) AS current_borrowers
    FROM borrowing_records
    WHERE return_date IS NULL
    GROUP BY book_id
)

SELECT
    b.book_id,
    b.title,
    b.author,
    b.genre,
    b.publication_year,
    bc.current_borrowers
FROM library_books b
JOIN borrow_count bc
    ON b.book_id = bc.book_id
WHERE bc.current_borrowers = b.total_copies
ORDER BY 
    bc.current_borrowers DESC,
    b.title ASC;
