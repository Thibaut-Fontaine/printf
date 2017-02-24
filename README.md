# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    README.md                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfontain <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/24 18:42:36 by tfontain          #+#    #+#              #
#    Updated: 2017/02/24 19:33:21 by tfontain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Fonctionnement du printf :

toutes les fonctions head appellent vd_printf qui specifie un fd & un lstarg
lstarg appelle une une ft pour chaque argument et envoie systematiquement un pt
sur le prochain '%' rencontre, sauf si c'est un "%%".

cette fonction cherche l'indicateur de conv et renvoie un pointeur sur fonction
correspondant au bon format.
