FROM gcc:latest

COPY . /usr/src/logreader
WORKDIR /usr/src/logreader
RUN g++ -o logreader main.cpp
CMD ["./logreader","log.dat"]