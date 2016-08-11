create database mqtt_data;
use mqtt_data;
create table ph(
    id int auto_increment primary key not null,
    value float,
    cur_time time,
    cur_date date
);

create table ph_temp(
    id int auto_increment primary key not null,
    value float,
    cur_time time,
    cur_date date
);
create table orp(
    id int auto_increment primary key not null,
    value float,
    cur_time time,
    cur_date date
);
create table orp_temp(
    id int auto_increment primary key not null,
    value float,
    cur_time time,
    cur_date date
);
