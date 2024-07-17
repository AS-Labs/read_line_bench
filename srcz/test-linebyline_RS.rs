use std::fs::File;
use std::io::{self, BufRead, BufReader};

fn main() -> io::Result<()> {
    let file = File::open("data.txt")?;
    let reader = BufReader::new(file);

    let mut line_count = 0;
    let mut byte_count = 0;

    for line in reader.lines() {
        let line = line?;
        line_count += 1;
        byte_count += line.len();
    }

    println!("{} lines, {} bytes", line_count, byte_count);
    Ok(())
}
