FROM busybox
LABEL maintainer="joseph@bigfluffy.cloud"
LABEL author="joseph@bigfluffy.cloud"

# IRC over TLS
EXPOSE 6697/tcp
# WebIRC wss/https
EXPOSE 6680/tcp

# We need to start up our periodic maintenance task
# It will delete old PHP sessions and vacuum the database every now and then...
#ENTRYPOINT ["/bin/sh", "-c", "/xbin/startup.sh"]
ADD ./bin /bin
ADD ./conf /conf
ADD ./run /run
WORKDIR /run

#RUN ./xbin/build.sh
#CMD ["/bin/sh", "-c", "/xbin/startup.sh"]
