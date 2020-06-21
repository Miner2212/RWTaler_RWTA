#FROM debian:stretch
FROM ubuntu:18.04
LABEL maintainer="The RWTalercore Developers <216k155@spidervps.net>"
LABEL description="Dockerised RWTalercore, built from Travis"

RUN apt-get update && apt-get install -y software-properties-common unzip
RUN apt-get install -y wget

RUN wget https://github.com/SPDR-Core/rwtaler/releases/download/v5.2.3/rwtaler-qt-linux-18.zip
RUN unzip rwtaler-qt-linux-18.zip
RUN cp rwtalerd /usr/local/bin

VOLUME ["/opt/rwtaler"]

EXPOSE 53616
EXPOSE 53616
EXPOSE 9777
EXPOSE 9777

CMD ["rwtalerd", "--conf=/opt/rwtaler/rwtaler.conf", "--printtoconsole"]