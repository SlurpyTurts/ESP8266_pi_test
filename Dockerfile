FROM httpd:2.4
COPY test_data_in.php /
COPY send_data_php/* /