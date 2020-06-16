#Desabilite a linha abaixo caso o pacote ainda nao foi instalado no sistema
#install.packages("FrF2", repos = "http://cran.rstudio.com/") # Instala o pacote

library(FrF2) # Carrega o pacote para uso

plan.person = FrF2(nruns = 4,
                   nfactors =  2,
                   replications = 1,
                   repeat.only = FALSE,
                   factor.names = list(
                     Tecnica = c("Interchange", "Unrolling"),
                     Matriz = c("100", "1000")),
                   randomize = FALSE)

summary(plan.person)

# Valores de cada variável de resposta em cada experimento da Atividade 1 (RETIRE OS COMENTARIOS DEPENDENDO DE QUAL VARIAVEL QUISER VISUALIZAR):

##  `L1-dcache loads`
resultados = c(13151275, 13207135, 1322562515, 132053624)

##  `L1-dcache-load-misses`
# resultados = c(699053, 747244, 76626646, 77909924)

##  `branch instructions`
# resultados = c(10483632, 10465075, 1064390668, 1063787610)

##  `branch misses`
# resultados = c(236027, 237072, 23312796, 23884774)


plan.atualizado = add.response(design = plan.person, response = resultados)

summary(plan.atualizado)

MEPlot(plan.atualizado)

IAPlot(plan.atualizado)


# Modelo linear = resultados dependem (~) de Tecnica e Matriz
plan.formula = lm(plan.atualizado$resultados~(plan.atualizado$Tecnica*plan.atualizado$Matriz))

# A tabela fornecida na linha abaixo diz na coluna "Estimate" os valores de q0 (media), qA (Tecnica1), qB (Matriz1) e qAB (Tecnica e Matriz)
summary(plan.formula)

# Calculo das Somas dos Quadrados
plan.anova = anova(plan.formula)

# Valores das medias dos quadrados podem ser observados na tabela gerada pela linha abaixo
# na coluna "Mean Sq". 
summary(plan.anova$`Mean Sq`)

# C???lculo da Soma dos Quadrados Total
SST = plan.anova$"Mean Sq"[1] + plan.anova$"Mean Sq"[2] + plan.anova$"Mean Sq"[3]

#C???lculo da influ???ncia de cada fator
InfluenciaA = plan.anova$"Mean Sq"[1] / SST
InfluenciaB = plan.anova$"Mean Sq"[2] / SST
InfluenciaAB = plan.anova$"Mean Sq"[3] / SST

cat("\n\nInfluencia devido ao fator Tecnica:", InfluenciaA)
cat("\nInfluencia devido ao fator Matriz:", InfluenciaB)
cat("\nInfluencia devido a interacaoo dos fatores:", InfluenciaAB)
cat("\n\n")
