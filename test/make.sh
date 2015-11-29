cc -o client client.c date_clnt.c -lnsl
cc -o server -DRPC_SVG_FC server.c date_svc.c -lnsl
