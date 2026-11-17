use std::net::Ipv4Addr;
use std::net::SocketAddr;
use std::net::TcpStream;
use std::net::TcpListener;
use std::net::IpAddr;
use std::io::{self, Read};

fn main() -> io::Result<()> {
    let mut data: String = String::new();
    let target: Ipv4Addr = Ipv4Addr::new(127, 0, 0, 1);
    let target_address: SocketAddr = SocketAddr::new(IpAddr::V4(target), 6666);
    let target_listener: TcpListener = match TcpListener::bind(target_address) {
        Ok(v) => v,
        Err(e) => {
            eprintln!("Something wrong with the listener!");
            return Err(e);
        }
    };

    for stream in target_listener.incoming() {
        let mut target_stream: TcpStream = match stream {
            Ok(v) => v,
            Err(e) => {
                eprintln!("Something wrong with the stream!");
                return Err(e);
            }
        };

        let length: usize = match target_stream.read_to_string(&mut data) {
            Ok(v) => v,
            Err(e) => {
                eprintln!("Seems there's an error while reading string!");
                return Err(e);
            }
        };
        println!("Res: {}", data);
        println!("Byte Length: {}", length);
        data.drain(..);
    }

    return Ok(());
}
