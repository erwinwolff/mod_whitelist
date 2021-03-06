[![Documentation Status](https://readthedocs.org/projects/mod-whitelist/badge/?version=latest)](https://mod-whitelist.readthedocs.io/en/latest/?badge=latest) [![Language grade: C/C++](https://img.shields.io/lgtm/grade/cpp/g/erwinwolff/mod_whitelist.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/erwinwolff/mod_whitelist/context:cpp) [![Support Me](https://img.shields.io/badge/donate-Support%20Me-red)](https://www.paypal.com/cgi-bin/webscr?cmd=_donations&business=erwinwolffnl%40outlook.com&item_name=Support+me+for+developing+mod_whitelist&currency_code=EUR&source=url)

# Mod_Whitelist
## Why Mod_Whitelist?
Because sometimes you need simple IP based filtering. It is manageable from a MySQL table, it is up to you to fill the MySQL table. Its components are:

* CMake (for development only)
* [Apache 2.4](https://httpd.apache.org/)
* Either [MySQL](https://www.mysql.com/) or [MariaDB](https://mariadb.com/)
* mod_whitelist

## Possible usages
Some ideas to put mod_whitelist to work. 
* To put some sort of security in place for a old software that is too expensive to update
* Secure resources like REST endpoints who do not have security rolled out as part of their implementation
* As a compromise for if firewall-level ip-filtering is too difficult to setup and when securtiy on application-level ip-filtering is too difficult or resource-intensive

## Why was it created?
Because I needed it ;) 

## How do I configure it?
Configuration is very simple.

Inside a vhost you just set these parameters:
* WhiteListMySqlEnabled On
* WhiteListMySqlConnectrionstring "Server=localhost;Database=Testdb;User=test;Password=test;Port=3306"
* WhiteListMySqlQuery "SELECT Ip FROM allowedips"

## How do I compile it?
Building from source is very easy (on debian-clones):

* cmake .
* make
* ./apxs.sh 
* service apache2 restart

## Future
- [x] Should be easily compiled with simple buildchain
- [x] Should block all ip's not on the whitelist
- [x] Should be easily configurable
- [ ] Should accept ip-address ranges
- [ ] Debian and Ubuntu packaging
- [ ] Redhat-variations packaging

## Do you accepted pull-requests?
It depends, if it really adds something. I don't want to have this piece of C++ code solve every problem in the world, so keep pull requests focused towards whitelisting ip-addresses based on a database provided list.
