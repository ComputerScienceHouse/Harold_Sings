Harold: harold.o ldap_csh.o harold_log.o
	gcc -o Harold harold.o ldap_csh.o harold_log.o -O3 -lldap -Wall -Wextra -lpthread -lwiringPi

harold.o: harold.c
	gcc -c harold.c -O3 -Wall -Wextra

ldap_csh.o: ldap_csh.c
	gcc -c ldap_csh.c -O3 -Wall -Wextra -Wno-implicit-function-declaration

harold_log.o: harold_log.c
	gcc -c harold_log.c -O3 -Wall -Wextra

clean:
	rm *.o
	rm Harold
