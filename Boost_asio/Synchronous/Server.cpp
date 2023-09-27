// 서버 Server.cpp

#include <iostream>
#include <boost/asio.hpp>

const char SERVER_IP[] = "127.0.0.1";
const unsigned short PORT_NUMBER = 3000;

int main() {
    boost::asio::io_service io_service;
    boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::tcp::v4(), PORT_NUMBER);
    // endpoint : 네트워크 주소설정, 이 주소로 클라이언트가 접속
    // 서버는 IP주소체계(IPv4 or IPv6)와 포트번호 사용, 
    boost::asio::ip::tcp::acceptor acceptor(io_service, endpoint);
    // acceptor : 클라이언트 접속을 받아들이는 역할 (io_service를 인수로 넘겨야함), endpoint에 접속이 됐는지 확인하기 위해 endpoint도 같이 넘겨줌

    // socket : 접속한 클라이언트에 할당할 소켓을 만듬, 소켓을 통해 클라이언트가 보낸 메세지를 주고 받음
    boost::asio::ip::tcp::socket socket(io_service);
    acceptor.accept(socket); // 클라이언트 접속을 받아들임

    std::cout << "클라이언트 접속" << std::endl;

    // 접속한 클라이언트가 있다면 서버를 무한루프(for(;;)로 돌림
    for (;;) {
        char buf[128] = { 0 }; // buf : 클라가 보내는 메세지를 담을 버퍼
        boost::system::error_code error;
        size_t len = socket.read_some(boost::asio::buffer(buf), error);
        // read_some : 클라가 보낸 메세지를 buffer 타입으로 buf에 받음, 에러코드 발생 대비 error도 넘기고 실패시, error에 에러코드 담김
        // 성공적으로 클라이언트가 보낸 데이터를 받으면 받은 데이터 크기를 리턴

        // 동기식 서버이므로 데이터를 다 받을 때까지 대기상태

        if (error) { // error가 NULL값이 아니면 error가 발생하여 에러코드가 담겨있다는 뜻임
            if (error = boost::asio::error::eof) //  error코드가 eof면 클라이언트의 접속이 끊어짐
                std::cout << "클라이언트와 연결이 끊어졌습니다." << std::endl;
            else
                std::cout << "error No : " << error.value() << "error Message : " << error.message() << std::endl; // 코드가 존재한다면 에러메세지 출력
            break;
        }

        std::cout << "클라이언트에서 받은 메세지 : " << &buf[0] << std::endl;
        char szMessage[128] = { 0, }; // szMessage : 클라이언트에게 보낼 메세지를 담는 버퍼
        sprintf_s(szMessage, 128 - 1, "Re:%s", &buf[0]);
        int nMsgLen = strnlen(szMessage, 128 - 1);// szMessage의 길이

        boost::system::error_code ignored_error;
        socket.write_some(boost::asio::buffer(szMessage, nMsgLen), ignored_error);
    }
    getchar();
}