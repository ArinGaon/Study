// ���� Server.cpp

#include <iostream>
#include <boost/asio.hpp>

const char SERVER_IP[] = "127.0.0.1";
const unsigned short PORT_NUMBER = 3000;

int main() {
    boost::asio::io_service io_service;
    boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::tcp::v4(), PORT_NUMBER);
    // endpoint : ��Ʈ��ũ �ּҼ���, �� �ּҷ� Ŭ���̾�Ʈ�� ����
    // ������ IP�ּ�ü��(IPv4 or IPv6)�� ��Ʈ��ȣ ���, 
    boost::asio::ip::tcp::acceptor acceptor(io_service, endpoint);
    // acceptor : Ŭ���̾�Ʈ ������ �޾Ƶ��̴� ���� (io_service�� �μ��� �Ѱܾ���), endpoint�� ������ �ƴ��� Ȯ���ϱ� ���� endpoint�� ���� �Ѱ���

    // socket : ������ Ŭ���̾�Ʈ�� �Ҵ��� ������ ����, ������ ���� Ŭ���̾�Ʈ�� ���� �޼����� �ְ� ����
    boost::asio::ip::tcp::socket socket(io_service);
    acceptor.accept(socket); // Ŭ���̾�Ʈ ������ �޾Ƶ���

    std::cout << "Ŭ���̾�Ʈ ����" << std::endl;

    // ������ Ŭ���̾�Ʈ�� �ִٸ� ������ ���ѷ���(for(;;)�� ����
    for (;;) {
        char buf[128] = { 0 }; // buf : Ŭ�� ������ �޼����� ���� ����
        boost::system::error_code error;
        size_t len = socket.read_some(boost::asio::buffer(buf), error);
        // read_some : Ŭ�� ���� �޼����� buffer Ÿ������ buf�� ����, �����ڵ� �߻� ��� error�� �ѱ�� ���н�, error�� �����ڵ� ���
        // ���������� Ŭ���̾�Ʈ�� ���� �����͸� ������ ���� ������ ũ�⸦ ����

        // ����� �����̹Ƿ� �����͸� �� ���� ������ ������

        if (error) { // error�� NULL���� �ƴϸ� error�� �߻��Ͽ� �����ڵ尡 ����ִٴ� ����
            if (error = boost::asio::error::eof) //  error�ڵ尡 eof�� Ŭ���̾�Ʈ�� ������ ������
                std::cout << "Ŭ���̾�Ʈ�� ������ ���������ϴ�." << std::endl;
            else
                std::cout << "error No : " << error.value() << "error Message : " << error.message() << std::endl; // �ڵ尡 �����Ѵٸ� �����޼��� ���
            break;
        }

        std::cout << "Ŭ���̾�Ʈ���� ���� �޼��� : " << &buf[0] << std::endl;
        char szMessage[128] = { 0, }; // szMessage : Ŭ���̾�Ʈ���� ���� �޼����� ��� ����
        sprintf_s(szMessage, 128 - 1, "Re:%s", &buf[0]);
        int nMsgLen = strnlen(szMessage, 128 - 1);// szMessage�� ����

        boost::system::error_code ignored_error;
        socket.write_some(boost::asio::buffer(szMessage, nMsgLen), ignored_error);
    }
    getchar();
}