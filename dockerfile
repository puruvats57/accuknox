FROM gcc:latest

COPY . /assign
WORKDIR /assign
RUN g++ -o assign.out main.cpp
CMD ["./assign.out","log.dat"]
