// The solution function accepts one parameter n of type i32
fn solution(n: i32) -> i32 {
    // Check if n less than or equal to 0
    if n <= 0 {
        0
    } else {
        // If n is positive, an iterator from 1 to n (1..n) is used,
        // which is filtered in such a way as to leave only those numbers that are divisible by 3 or 5.
        // This is checked using the condition x % 3 == 0 || x % 5 == 0.
        // Application of the method .filter() creates a new iterator from numbers satisfying the multiplicity condition.
        // The aggregate function .sum() adds up all the elements of the filtered iterator,
        // returning the total amount that the solution function returns.
        (1..n).filter(|&x| x % 3 == 0 || x % 5 == 0).sum()
    }
}

fn main() {
    println!("{}", solution(10));
}