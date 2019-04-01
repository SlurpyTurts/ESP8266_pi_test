FROM httpd:2.4
FROM php:7.2-cli
COPY . /usr/src/myapp
WORKDIR /usr/src/myapp