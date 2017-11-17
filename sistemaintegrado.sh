#!/bin/bash
echo "****** SISTEMA INTEGRADO ******"
echo "1 - Contabilidade"
echo "2 - Vendas"
echo "3 - Sair"
echo "*******************************"
echo "Qual deseja escolher?"
read OPCAO
cd "/home/labsisop/Desktop"
case $OPCAO in
1)./contabilidade ;;
2)./vendas ;;
3)./sair ;; 
*)
esac
	
