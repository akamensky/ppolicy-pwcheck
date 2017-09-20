# ppolicy-pwcheck
Very simplistic password checking for OpenLDAP ppolicy. It only checks if password contains characters from certain groups. If built as-is it checks if password contains at least one character from A-Z, a-z and 0-9. It does not check password length as this is done by ppolicy itself (see `man slapo-ppolicy`).

## Build
Below is example how it can be built on RHEL based systems:

```
# yum groupinstall "Development Tools"
# yumdownloader --source openldap
# rpm -i openldap*.src.rpm
# rpmbuild -dc /root/rpmbuild/SPECS/openldap.spec
# git clone https://github.com/akamensky/ppolicy-pwcheck.git
# cd ppolicy-pwcheck
# mkdir openldap
# src_dir="/root/rpmbuild/BUILD/openldap-<version>/openldap-<version>
# cp -r $src_dir/include $src_dir/libraries $src_dir/servers ./openldap/
# make
```


## Install

The build produces `pwcheck.so` file that should be copied to OpenLDAP libdir. Usually it will be `/usr/lib64/openldap/` or similar directory.

```
# cp ./pwcheck.so /usr/lib64/openldap/
```

## Configure

Using this module requires password policy entry to have a specific `objectClass` assigned before the module can be loaded:

```
# ldapmodify -Y EXTERNAL -H ldapi:///
dn: cn=ppolicy,ou=Policies,dc=example,dc=com
changetype: modify
add: objectClass
objectClass: pwdPolicyChecker
-
add: pwdCheckModule
pwdCheckModule: pwcheck.so
```

Once that is done on each password update the new password will be verified by the module (see `man slapo-ppolicy`).

## Contributing

Feel free to submit issue or PR.
