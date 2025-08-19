#!/usr/bin/perl
use strict;
use warnings;
use List::Util qw(shuffle);

# Fonction pour générer une grille complète valide
sub generate_full_grid {
    my @base = (1..9);
    my @rows;
    my @rbase = shuffle(0,1,2);
    my @rows_idx = map { my $r = $_; map { $r * 3 + $_ } @rbase } @rbase;
    my @cols_idx = @rows_idx;
    my @nums = shuffle(@base);

    for my $r (@rows_idx) {
        my @row;
        for my $c (@cols_idx) {
            push @row, $nums[ (3*($r % 3) + int($r/3) + $c) % 9 ];
        }
        push @rows, \@row;
    }
    return \@rows;
}

# Supprimer des cases selon la densité
sub remove_cells {
    my ($grid, $density) = @_;
    my @new_grid;
    for my $i (0..8) {
        my $row = '';
        for my $j (0..8) {
            if (rand() < $density) {
                $row .= $grid->[$i][$j];
            } else {
                $row .= '.';
            }
        }
        push @new_grid, $row;
    }
    return \@new_grid;
}

# Entrée utilisateur
die "Usage: $0 density (entre 0 et 1)\n" unless @ARGV == 1;
my $density = shift;
die "Density must be between 0 and 1\n" unless $density >= 0 && $density <= 1;

# Génération et affichage
my $full_grid = generate_full_grid();
my $puzzle = remove_cells($full_grid, $density);
print "$_\n" for @$puzzle;
