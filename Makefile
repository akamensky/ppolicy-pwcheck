CC=gcc

OPT=-O2 -Wall -fpic -std=gnu99

LDAP_INC_PATH=./openldap

LDAP_INC=-I$(LDAP_INC_PATH)/include -I$(LDAP_INC_PATH)/servers/slapd

INCS=$(LDAP_INC)

LDAP_LIB=-lldap_r -llber

LIBS=$(LDAP_LIB)

LIBDIR=/usr/lib64/openldap/


all: pwcheck

pwcheck.o:
	$(CC) $(OPT) -c $(INCS) pwcheck.c

pwcheck: clean pwcheck.o
	$(CC) -shared -o pwcheck.so pwcheck.o

clean:
	$(RM) pwcheck.so pwcheck.o

distclean: clean
	$(RM) -rf openldap
