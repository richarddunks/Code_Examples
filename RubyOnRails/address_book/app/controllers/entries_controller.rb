class EntriesController < ApplicationController
#	include EntriesHelper
	
  respond_to :html

  before_filter :find_entry, only: [:show, :update, :edit, :destroy]
  before_filter :build_children, only: [:new, :edit]
	before_filter :get_entries

  def index
    respond_with(@entries)
  end

  def show
    respond_with(@entry)
  end

  def new
    respond_with(@entry)
  end

  def edit
    respond_with(@entry)
  end

  def create
    @entry = Entry.new(params[:entry])
    if (@entry.save)
      flash_notice('created')
    else 
    	#:nocov:
      build_children
      #:nocov:
    end  
    respond_with(@entry)
  end

  def update
    flash_notice('updated') if @entry.update_attributes(
      params[:entry]
      )
    respond_with(@entry)
  end

  def destroy
    @entry.destroy
    flash_notice('deleted')
    redirect_to entries_url
  end

private

	def find_entry
		@entry = Entry.find(params[:id])
		params[:initial] = @entry.last_name[0]
	end

  def build_children
    @entry ||= Entry.new
    @entry.addresses.build
    @entry.emails.build
    @entry.webs.build
  end

	def get_entries
		criteria = 
			if params[:search]
				param = "#{params[:search].downcase}%"
				["lower(last_name) like ? or lower(first_name) like ?", param, param]
			else
				['substr(last_name,1,1) = ?', params[:initial]||'A']
			end	

		@entries = Entry.where(criteria).order('last_name, first_name')
	end

	def flash_notice(msg)
		flash[:notice] = "#{@entry.full_name} #{msg}"
	end

end
